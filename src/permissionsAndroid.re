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

  [@bs.module "react-native"] [@bs.scope "PermissionsAndroid"]
  external read_calendar : string = "READ_CALENDAR";
  [@bs.module "react-native"] [@bs.scope "PermissionsAndroid"]
  external write_calendar : string = "WRITE_CALENDAR";
  [@bs.module "react-native"] [@bs.scope "PermissionsAndroid"]
  external camera : string = "CAMERA";
  [@bs.module "react-native"] [@bs.scope "PermissionsAndroid"]
  external read_contacts : string = "READ_CONTACTS";
  [@bs.module "react-native"] [@bs.scope "PermissionsAndroid"]
  external write_contacts : string = "WRITE_CONTACTS";
  [@bs.module "react-native"] [@bs.scope "PermissionsAndroid"]
  external get_accounts : string = "GET_ACCOUNTS";
  [@bs.module "react-native"] [@bs.scope "PermissionsAndroid"]
  external access_fine_location : string = "ACCESS_FINE_LOCATION";
  [@bs.module "react-native"] [@bs.scope "PermissionsAndroid"]
  external access_coarse_location : string = "ACCESS_COARSE_LOCATION";
  [@bs.module "react-native"] [@bs.scope "PermissionsAndroid"]
  external record_audio : string = "RECORD_AUDIO";
  [@bs.module "react-native"] [@bs.scope "PermissionsAndroid"]
  external read_phone_state : string = "READ_PHONE_STATE";
  [@bs.module "react-native"] [@bs.scope "PermissionsAndroid"]
  external call_phone : string = "CALL_PHONE";
  [@bs.module "react-native"] [@bs.scope "PermissionsAndroid"]
  external read_call_log : string = "READ_CALL_LOG";
  [@bs.module "react-native"] [@bs.scope "PermissionsAndroid"]
  external write_call_log : string = "WRITE_CALL_LOG";
  [@bs.module "react-native"] [@bs.scope "PermissionsAndroid"]
  external add_voicemail : string = "ADD_VOICEMAIL";
  [@bs.module "react-native"] [@bs.scope "PermissionsAndroid"]
  external use_sip : string = "USE_SIP";
  [@bs.module "react-native"] [@bs.scope "PermissionsAndroid"]
  external process_outgoing_calls : string = "PROCESS_OUTGOING_CALLS";
  [@bs.module "react-native"] [@bs.scope "PermissionsAndroid"]
  external body_sensors : string = "BODY_SENSORS";
  [@bs.module "react-native"] [@bs.scope "PermissionsAndroid"]
  external send_sms : string = "send_sms";
  [@bs.module "react-native"] [@bs.scope "PermissionsAndroid"]
  external receive_sms : string = "RECEIVE_SMS";
  [@bs.module "react-native"] [@bs.scope "PermissionsAndroid"]
  external read_sms : string = "READ_SMS";
  [@bs.module "react-native"] [@bs.scope "PermissionsAndroid"]
  external receive_wap_push : string = "RECEIVE_WAP_PUSH";
  [@bs.module "react-native"] [@bs.scope "PermissionsAndroid"]
  external receive_mms : string = "RECEIVE_MMS";
  [@bs.module "react-native"] [@bs.scope "PermissionsAndroid"]
  external read_external_storage : string = "READ_EXTERNAL_STORAGE";
  [@bs.module "react-native"] [@bs.scope "PermissionsAndroid"]
  external write_external_storage : string = "WRITE_EXTERNAL_STORAGE";

  let getPermission = value =>
    switch (value) {
    | READ_CALENDAR => read_calendar
    | WRITE_CALENDAR => write_calendar
    | CAMERA => camera
    | READ_CONTACTS => read_contacts
    | WRITE_CONTACTS => write_contacts
    | GET_ACCOUNTS => get_accounts
    | ACCESS_FINE_LOCATION => access_fine_location
    | ACCESS_COARSE_LOCATION => access_coarse_location
    | RECORD_AUDIO => record_audio
    | READ_PHONE_STATE => read_phone_state
    | CALL_PHONE => call_phone
    | READ_CALL_LOG => read_call_log
    | WRITE_CALL_LOG => write_call_log
    | ADD_VOICEMAIL => add_voicemail
    | USE_SIP => use_sip
    | PROCESS_OUTGOING_CALLS => process_outgoing_calls
    | BODY_SENSORS => body_sensors
    | SEND_SMS => send_sms
    | RECEIVE_SMS => receive_sms
    | READ_SMS => read_sms
    | RECEIVE_WAP_PUSH => receive_wap_push
    | RECEIVE_MMS => receive_mms
    | READ_EXTERNAL_STORAGE => read_external_storage
    | WRITE_EXTERNAL_STORAGE => write_external_storage
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
  Js.log(Permission.getPermission(permission));
  _request(Permission.getPermission(permission), rationale);
};

[@bs.module "react-native"] [@bs.scope "PermissionsAndroid"]
external requestMultiple : array(Permission.t) => unit = "";