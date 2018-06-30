type rationale = {
  .
  "title": string,
  "message": string,
};

module Permission = {
  type t =
    | READ_CALENDAR
    | WRITE_CALENDAR
    | CAMERA
    | READ_CONTACTS
    | WRITE_CONTACTS
    | GET_ACCOUNTS
    | ACCESS_FINE_LOCATION
    | ACCESS_COARSE_LOCATION
    | RECORD_AUDIO
    | READ_PHONE_STATE
    | CALL_PHONE
    | READ_CALL_LOG
    | WRITE_CALL_LOG
    | ADD_VOICEMAIL
    | USE_SIP
    | PROCESS_OUTGOING_CALLS
    | BODY_SENSORS
    | SEND_SMS
    | RECEIVE_SMS
    | READ_SMS
    | RECEIVE_WAP_PUSH
    | RECEIVE_MMS
    | READ_EXTERNAL_STORAGE
    | WRITE_EXTERNAL_STORAGE;

  let getPermission = value =>
    switch (value) {
    | READ_CALENDAR => "android.permission.READ_CALENDAR"
    | WRITE_CALENDAR => "android.permission.WRITE_CALENDAR"
    | CAMERA => "android.permission.CAMERA"
    | READ_CONTACTS => "android.permission.READ_CONTACTS"
    | WRITE_CONTACTS => "android.permission.WRITE_CONTACTS"
    | GET_ACCOUNTS => "android.permission.GET_ACCOUNTS"
    | ACCESS_FINE_LOCATION => "android.permission.ACCESS_FINE_LOCATION"
    | ACCESS_COARSE_LOCATION => "android.permission.ACCESS_COARSE_LOCATION"
    | RECORD_AUDIO => "android.permission.RECORD_AUDIO"
    | READ_PHONE_STATE => "android.permission.READ_PHONE_STATE"
    | CALL_PHONE => "android.permission.CALL_PHONE"
    | READ_CALL_LOG => "android.permission.READ_CALL_LOG"
    | WRITE_CALL_LOG => "android.permission.WRITE_CALL_LOG"
    | ADD_VOICEMAIL => "android.voicemail.permission.ADD_VOICEMAIL"
    | USE_SIP => "android.permission.USE_SIP"
    | PROCESS_OUTGOING_CALLS => "android.permission.PROCESS_OUTGOING_CALLS"
    | BODY_SENSORS => "android.permission.BODY_SENSORS"
    | SEND_SMS => "android.permission.SEND_SMS"
    | RECEIVE_SMS => "android.permission.RECEIVE_SMS"
    | READ_SMS => "android.permission.READ_SMS"
    | RECEIVE_WAP_PUSH => "android.permission.RECEIVE_WAP_PUSH"
    | RECEIVE_MMS => "android.permission.RECEIVE_MMS"
    | READ_EXTERNAL_STORAGE => "android.permission.READ_EXTERNAL_STORAGE"
    | WRITE_EXTERNAL_STORAGE => "android.permission.WRITE_EXTERNAL_STORAGE"
    };
};

type results =
  | GRANTED
  | DENIED
  | NEVER_ASK_AGAIN;

let result = result =>
  switch (result) {
  | GRANTED => "GRANTED"
  | DENIED => "DENIED"
  | NEVER_ASK_AGAIN => "NEVER_ASK_AGAIN"
  };

[@bs.module "react-native"] [@bs.scope "PermissionsAndroid"]
external _check : string => Js.Promise.t(bool) = "check";

let check = permission => _check(Permission.getPermission(permission));

[@bs.module "react-native"] [@bs.scope "PermissionsAndroid"]
external _request : (string, rationale) => Js.Promise.t(string) = "request";

let request = (permission, rationale) => {
  Js.log(permission);
  _request(Permission.getPermission(permission), rationale);
};

[@bs.module "react-native"] [@bs.scope "PermissionsAndroid"]
external requestMultiple : array(Permission.t) => unit = "";