open Rebolt;
open Utils;

let exampleType = Multiple;

let displayName = "PermissionsAndroid";

let title = "PermissionsAndroid";

let description = "Example of getting CAMERA via PermissionsAndroid (only Android)";

module ExampleContent = {
  let component =
    ReasonReact.statelessComponent("PermissionsAndroidExampleContent");

  let requestPermissions = () =>
    PermissionsAndroid.request(
      PermissionsAndroid.Permission.SEND_SMS,
      {"title": "Hi!", "message": "Give me permissions!"},
    )
    |> Js.Promise.then_(request =>
         PermissionsAndroid.check(PermissionsAndroid.Permission.SEND_SMS)
         |> Js.Promise.then_(check => {
              Js.log({
                "permission": PermissionsAndroid.Permission.SEND_SMS,
                "version": Platform.version(),
                "request": request,
                "check": check,
              });
              Js.Promise.resolve("res");
            })
       )
    |> ignore;

  let make = _children => {
    ...component,
    render: _children => {
      requestPermissions();

      <TouchableNativeFeedback
        background=(TouchableNativeFeedback.selectableBackground())
        onPress=requestPermissions>
        <View style=Style.(style([backgroundColor(String("#03DAC5"))]))>
          <Text
            style=Style.(
                    style([
                      marginVertical(Pt(20.)),
                      textAlign(Center),
                      fontSize(Float(20.)),
                    ])
                  )>
            (ReasonReact.string("Get CAMERA permission"))
          </Text>
        </View>
      </TouchableNativeFeedback>;
    },
  };
};

let examples: array(Example.t) = [|
  {
    title: "PermissionsAndroid",
    description: Some("Base example"),
    render: () => <ExampleContent />,
  },
|];