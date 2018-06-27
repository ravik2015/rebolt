let make:
  (
    ~maskElement: 'a,
    ~accessible: 'b=?,
    ~accessibilityLabel: 'c=?,
    ~accessibilityComponentType: [<
                                   | `button
                                   | `none
                                   | `radiobutton_checked
                                   | `radiobutton_unchecked
                                 ]
                                   =?,
    ~accessibilityTraits: list(
                            [<
                              | `adjustable
                              | `allowsDirectInteraction
                              | `button
                              | `disabled
                              | `frequentUpdates
                              | `header
                              | `image
                              | `key
                              | `link
                              | `none
                              | `pageTurn
                              | `plays
                              | `search
                              | `selected
                              | `startsMedia
                              | `summary
                              | `text
                            ],
                          )
                            =?,
    ~onAccessibilityTap: 'd=?,
    ~hitSlop: 'e=?,
    ~onLayout: 'f=?,
    ~onMagicTap: 'g=?,
    ~responderHandlers: Rebolt.Types.touchResponderHandlers=?,
    ~pointerEvents: [< | `auto | `boxNone | `boxOnly | `none]=?,
    ~removeClippedSubviews: 'h=?,
    ~style: 'i=?,
    ~testID: 'j=?,
    ~accessibilityLiveRegion: [< | `assertive | `none | `polite]=?,
    ~collapsable: 'k=?,
    ~importantForAccessibility: [< | `auto | `no | `noHideDescendants | `yes]=?,
    ~needsOffscreenAlphaCompositing: 'l=?,
    ~renderToHardwareTextureAndroid: 'm=?,
    ~accessibilityViewIsModal: 'n=?,
    ~shouldRasterizeIOS: 'o=?,
    'p
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    ReasonReact.actionless,
  );
