require("dotenv").config({
  path: `.env.${process.env.NODE_ENV}`,
})

module.exports = {
  siteMetadata: {
    title: `LifeBlood`,
    description: `A site for analyzing and tracking blood test results over time.`,
  },
  plugins: [
    {
      resolve: "@jfrolich/gatsby-plugin-extract-schema",
      options: {
        dest: `${__dirname}/graphql_schema.json`,
      },
    },
    `@jfrolich/gatsby-plugin-reason`,
    `gatsby-plugin-netlify`,
    {
      resolve: `@prismicio/gatsby-source-prismic-graphql`,
      options: {
        repositoryName: `lifeblood`,
        accessToken: `${process.env.API_KEY}`,
      },
    },
  ],
}
