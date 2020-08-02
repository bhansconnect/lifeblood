module.exports = {
  globals: {
    __PATH_PREFIX__: true,
  },
  extends: `react-app`,
  overrides: [
    {
      excludedFiles: "*.bs.js",
    },
  ],
}
