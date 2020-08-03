[%graphql
  {|
  query{
    allStrapiLabResult {
      nodes {
        id
        name
        description
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
  let {allStrapiLabResult: {nodes}} = parse(data);
  <div>
    {Belt.Array.map(
       nodes,
       fun
       | {id, name: Some(name), description: Some(description)} => {
           <div key=id>
             <div className=Styles.title> {React.string(name)} </div>
             <ReactMarkdown source=description />
           </div>;
         }
       | _ => React.null,
     )
     ->React.array}
    <div> {React.string("My location is: " ++ location.pathname)} </div>
  </div>;
};

let default = make;
