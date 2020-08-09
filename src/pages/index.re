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

[@react.component]
let make = (~data, ~location: Gatsby.location) => {
  let {allStrapiLabResult: {nodes}} = parse(data);
  <Layout>
    <SEO />
    {Belt.Array.map(
       nodes,
       fun
       | {id, name: Some(name), description: Some(description)} => {
           <div key=id>
             <div className=Styles.title> {React.string(name)} </div>
             <Markdown source=description />
           </div>;
         }
       | _ => React.null,
     )
     ->React.array}
    <div> {React.string("My location is: " ++ location.pathname)} </div>
  </Layout>;
};

let default = make;
