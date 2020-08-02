[%graphql
  {|
  query {
    siteBuildMetadata {
      buildTime
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
  | {siteBuildMetadata: Some({buildTime: Some(buildTime)})} =>
    let buildString = Js_json.decodeString(buildTime);
    switch (buildString) {
    | Some(build) =>
      Js.log(location);
      <div>
        <div className=Styles.title>
          {React.string("I was built at: " ++ build)}
        </div>
        <div> {React.string("My location is: " ++ location.pathname)} </div>
      </div>;
    | _ => React.null
    };
  | _ => React.null
  };
};

let default = make;
