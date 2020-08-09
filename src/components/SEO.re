[%graphql
  {|
    query{
      site {
        siteMetadata {
          title
          description
          image
        }
      }
    }
  |};
  {inline: true}
];

[@react.component]
let make = (~description=?, ~lang="en", ~meta as passedMeta=[||], ~title=?) => {
  // We need to parse the query to get ReasonML runtime types.
  let site = Gatsby.useStaticQuery(query)->unsafe_fromJson->parse.site;

  let metaTitle =
    switch (title, site) {
    | (Some(title), Some({siteMetadata: Some({title: Some(siteTitle)})})) =>
      Some(title ++ " | " ++ siteTitle)
    | (_, Some({siteMetadata: Some({title: optionSiteTitle})})) => optionSiteTitle
    | _ => None
    };

  let image =
    switch (site) {
    | Some({siteMetadata: Some({image})}) => image
    | _ => None
    };

  let metaDescription =
    switch (description, site) {
    | (Some(description), _) => Some(description)
    | (_, Some({siteMetadata: Some({description: Some(description)})})) =>
      Some(description)
    | _ => None
    };

  <Helmet
    title={metaTitle->Belt.Option.getWithDefault("LifeBlood")}
    defer=false
    htmlAttributes={lang: lang}
    meta=Helmet.(
      [|
        Belt.Option.map(metaDescription, description =>
          meta(~name="description", ~content=description, ())
        ),
        Belt.Option.map(metaTitle, title =>
          meta(~property="og:title", ~content=title, ())
        ),
        Belt.Option.map(metaDescription, description =>
          meta(~property="og:description", ~content=description, ())
        ),
        Belt.Option.map(image, image =>
          meta(~property="og:image", ~content=image, ())
        ),
        Some(meta(~property="og:type", ~content="website", ())),
      |]
      ->Belt.Array.keepMap(a => a)
      |> Js.Array.concat(passedMeta)
    )
  />;
};

let default = make;
