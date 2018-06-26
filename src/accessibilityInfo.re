[@bs.module "react-native"] [@bs.scope "AccessibilityInfo"]
external fetch : unit => unit = "";

[@bs.module "react-native"] [@bs.scope "AccessibilityInfo"]
external addEventListener : (string, unit => unit) => unit = "";

[@bs.module "react-native"] [@bs.scope "AccessibilityInfo"]
external setAccessibilityFocus : string => unit = "";

[@bs.module "react-native"] [@bs.scope "AccessibilityInfo"]
external announceForAccessibility : string => unit = "";

[@bs.module "react-native"] [@bs.scope "AccessibilityInfo"]
external removeEventListener : (string, unit => unit) => unit = "";