require(`dotenv`).config({
  path: `.env.${process.env.NODE_ENV}`,
})

module.exports = {
  siteMetadata: {
    title: `LifeBlood`,
    description: `Analyze and track your blood test results over time. All data kept private and stored locally on your device.`,
    image: `https://lifeblood.app/icons/icon-512x512.png`,
  },
  plugins: [
    {
      resolve: `@jfrolich/gatsby-plugin-extract-schema`,
      options: {
        dest: `${__dirname}/graphql_schema.json`,
      },
    },
    `gatsby-plugin-react-helmet`,
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
    {
      resolve: `gatsby-plugin-manifest`,
      options: {
        name: `LifeBlood`,
        short_name: `LifeBlood`,
        description: `Analyze and track your blood test results over time. All data kept private and stored locally on your device.`,
        start_url: `/`,
        background_color: `#c8c8c8`,
        theme_color: `#ac0404`,
        display: `standalone`,
        cache_busting_mode: `none`,
        icon: `static/favicon.svg`,
        icons: [
          `48x48`,
          `72x72`,
          `96x96`,
          `144x144`,
          `192x192`,
          `256x256`,
          `384x384`,
          `512x512`,
        ].map(size => {
          return {
            src: `/icons/icon-${size}.png`,
            sizes: size,
            type: `image/png`,
          }
        }),
        icon_options: {
          purpose: `any maskable`,
        },
      },
    },
    {
      resolve: `gatsby-plugin-offline`,
      options: {
        precachePages: [],
        workboxConfig: {
          globPatterns: [`**/icons/*`],
        },
      },
    },
  ],
}
