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
    | READ_CALENDAR => "READ_CALENDAR"
    | WRITE_CALENDAR => "WRITE_CALENDAR"
    | CAMERA => "CAMERA"
    | READ_CONTACTS => "READ_CONTACTS"
    | WRITE_CONTACTS => "WRITE_CONTACTS"
    | GET_ACCOUNTS => "GET_ACCOUNTS"
    | ACCESS_FINE_LOCATION => "ACCESS_FINE_LOCATION"
    | ACCESS_COARSE_LOCATION => "ACCESS_COARSE_LOCATION"
    | RECORD_AUDIO => "RECORD_AUDIO"
    | READ_PHONE_STATE => "READ_PHONE_STATE"
    | CALL_PHONE => "CALL_PHONE"
    | READ_CALL_LOG => "READ_CALL_LOG"
    | WRITE_CALL_LOG => "WRITE_CALL_LOG"
    | ADD_VOICEMAIL => "ADD_VOICEMAIL"
    | USE_SIP => "USE_SIP"
    | PROCESS_OUTGOING_CALLS => "PROCESS_OUTGOING_CALLS"
    | BODY_SENSORS => "BODY_SENSORS"
    | SEND_SMS => "SEND_SMS"
    | RECEIVE_SMS => "RECEIVE_SMS"
    | READ_SMS => "READ_SMS"
    | RECEIVE_WAP_PUSH => "RECEIVE_WAP_PUSH"
    | RECEIVE_MMS => "RECEIVE_MMS"
    | READ_EXTERNAL_STORAGE => "READ_EXTERNAL_STORAGE"
    | WRITE_EXTERNAL_STORAGE => "WRITE_EXTERNAL_STORAGE"
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

let request = (permission, rationale) =>
  _request(Permission.getPermission(permission), rationale);
/*
 [@bs.send];
 external requestMultiple : array(Permission.t) => unit = ""; */