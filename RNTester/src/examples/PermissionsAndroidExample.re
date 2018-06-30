open Rebolt;
open Utils;

let exampleType = Multiple;

let displayName = "PermissionsAndroid";

let title = "PermissionsAndroid";

let description = "Example of getting CAMERA via PermissionsAndroid (only Android)";

module ExampleContent = {
  let component =
    ReasonReact.statelessComponent("PermissionsAndroidExampleContent");

  let requestPermissions = () => {
    Js.log(Platform.os());
    Js.log(Platform.version());
    PermissionsAndroid.request(
      PermissionsAndroid.Permission.SEND_SMS,
      {"title": "Hi!", "message": "Give me permissions!"},
    )
    |> Js.Promise.then_(request =>
         PermissionsAndroid.check(PermissionsAndroid.Permission.SEND_SMS)
         |> Js.Promise.then_(res => {
              Js.log(request);
              Js.log(res);
              Js.Promise.resolve("res");
            })
       )
    |> ignore;
  };

  let make = _children => {
    ...component,
    render: _children => {
      Js.log(Platform.os());
      Js.log(Platform.version());
      PermissionsAndroid.request(
        PermissionsAndroid.Permission.SEND_SMS,
        {"title": "elo", "message": "asd"},
      )
      |> Js.Promise.then_(request =>
           PermissionsAndroid.check(PermissionsAndroid.Permission.SEND_SMS)
           |> Js.Promise.then_(res => {
                Js.log(request);
                Js.log("elo");
                Js.log(res);
                Js.Promise.resolve();
              })
         )
      |> ignore;
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