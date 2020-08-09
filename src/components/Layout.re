[%graphql
  {|
    query{
      site {
        siteMetadata {
          title
          image
        }
      }
    }
  |};
  {inline: true}
];

[@react.component]
let make = (~children) => {
  let site = Gatsby.useStaticQuery(query)->unsafe_fromJson->parse.site;

  let title =
    switch (site) {
    | Some({siteMetadata: Some({title})}) => title
    | _ => None
    };

  let image =
    switch (site) {
    | Some({siteMetadata: Some({image})}) => image
    | _ => None
    };
  Css.(global("body", [margin(px(0))]));
  <div>
    <header className=Styles.header>
      <Gatsby.Link _to="/" className=Styles.blankLink>
        <img src="/icons/icon-48x48.png" className=Styles.headerIcon />
        {title->Belt.Option.mapWithDefault(React.null, title =>
           <div className=Styles.headerText> {React.string(title)} </div>
         )}
      </Gatsby.Link>
    </header>
    <nav />
    <main> children </main>
  </div>;
};
