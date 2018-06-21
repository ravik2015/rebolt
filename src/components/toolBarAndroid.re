[@bs.module "react-native"]
external toolBar : ReasonReact.reactClass = "ToolbarAndroid";

let make =
    (~title=?, ~contentInsetStart=?, ~contentInsetEnd=?, ~actions=?, ~style=?) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=toolBar,
    ~props=
      Props.extendView(
        Js.Undefined.(
          {
            "title": fromOption(title),
            "contentInsetStart": fromOption(contentInsetStart),
            "contentInsetEnd": fromOption(contentInsetEnd),
            "actions": fromOption(actions),
          }
        ),
        ~style,
      ),
  );