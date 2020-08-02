[%graphql
  {|
  query{
    prismic {
      allLab_results {
        edges {
          node {
            name
            description
          }
        }
      }
    }
  }
  |};
  {inine: true}
];
module Styles = {
  open Css;
  let title = style([fontSize(rem(2.5)), lineHeight(`abs(1.25))]);
};

[@react.component]
let make = (~data, ~location: Gatsby.location) => {
  switch (parse(data)) {
  | {prismic: {allLab_results: {edges: Some(edges)}}} =>
    <div>
      {Belt.Array.map(
         edges,
         fun
         | Some({node: {name: Some(name), description: Some(description)}}) =>
           <div key={Js.Json.stringifyWithSpace(name, 2)}>
             <div className=Styles.title>
               {React.string(Js.Json.stringifyWithSpace(name, 2))}
             </div>
             <div>
               {React.string(Js.Json.stringifyWithSpace(description, 2))}
             </div>
           </div>
         | _ => React.null,
       )
       ->React.array}
      <div> {React.string("My location is: " ++ location.pathname)} </div>
    </div>
  | _ => React.null
  };
};

let default = make;
