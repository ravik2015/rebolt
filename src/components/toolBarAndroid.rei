let make:
  (
    ~title: string=?,
    ~contentInsetStart: int=?,
    ~contentInsetEnd: int=?,
    ~actions: array(
                {
                  .
                  "title": string,
                  "show": bool,
                  "showWithText": bool,
                },
              )
                =?,
    ~style: Style.t=?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    ReasonReact.actionless,
  );