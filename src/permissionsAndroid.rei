type rationale = {
  .
  "title": string,
  "message": string,
};

module Permission: {
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
};

/* type results =
   | GRANTED
   | DENIED
   | NEVER_ASK_AGAIN; */

let check: Permission.t => Js.Promise.t(bool);

let request: (Permission.t, rationale) => Js.Promise.t(string);

/* let requestMultiple: array(Permission.t) => unit; */