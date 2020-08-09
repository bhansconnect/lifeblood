open Css;

let textColor = black;
let themeColor = hex("AC0404");
let themeSecondaryColor = hex("C8C8C8");

let title = style([fontSize(rem(2.5)), lineHeight(`abs(1.25))]);

let blankLink =
  style([boxShadow(none), textDecoration(none), color(textColor)]);

let header =
  style([
    display(inlineBlock),
    backgroundColor(themeColor),
    color(themeSecondaryColor),
    width(pct(100.)),
    padding(px(6)),
  ]);

let headerIcon =
  style([
    backgroundColor(themeSecondaryColor),
    borderRadius(pct(50.)),
    display(inlineBlock),
  ]);

let headerText =
  style([
    fontSize(rem(2.5)),
    lineHeight(`abs(1.25)),
    color(themeSecondaryColor),
    display(inlineBlock),
  ]);
