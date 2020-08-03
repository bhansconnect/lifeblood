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
      resolve: `gatsby-source-strapi`,
      options: {
        apiURL: `${process.env.STRAPI_URL}`,
        queryLimit: 1000, // Default to 100
        contentTypes: [`lab-result`],
        singleTypes: [],
        loginData: {
          identifier: `${process.env.STRAPI_IDENTIFIER}`,
          password: `${process.env.STRAPI_PASSWORD}`,
        },
      },
    },
  ],
}
