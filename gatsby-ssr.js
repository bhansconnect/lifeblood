import { renderToString } from "react-dom/server"
import { renderStylesToString } from "emotion-server"

export const replaceRenderer = ({ bodyComponent, replaceBodyHTMLString }) => {
  const bodyHTML = renderToString(bodyComponent)
  const resultHTML = renderStylesToString(bodyHTML)
  replaceBodyHTMLString(resultHTML)
}
