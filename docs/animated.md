---
id: animated
title: Animated
sidebar_label: Animated
---

## Example of use

`Animated` allows to create declarative animations that are fluid, powerful and easy to build.

### basic

The simplest animation starts with creating an animated value and using one of the built-in animations to change its value over time.

The following example demonstrates use of `Animated.Timing` in order to animate an animated value throughout given period of time.

```reason
open Rebolt;

let animatedValue = Animated.Value.create(0.0);

let animation =
  Animated.Timing.animate(
    ~value=animatedValue,
    ~toValue=`raw(1.0),
    ~duration=100.0,
    (),
  );

Animated.CompositeAnimation.start(animation, ~callback=_didFinish => (), ());
```

### multiple

Animations can be also combined together in complex ways using composition functions.

The following example demonstrates use of `Animated.sequence` in order to run animations in a sequence, one by one.

```reason
open Rebolt;

let animatedValue = Animated.Value.create(0.0);

let animation =
  Animated.sequence([|
    Animated.Timing.animate(
      ~value=animatedValue,
      ~toValue=`raw(1.0),
      ~duration=100.0,
      (),
    ),
    Animated.Timing.animate(
      ~value=animatedValue,
      ~toValue=`raw(0.0),
      ~duration=100.0,
      (),
    ),
  |]);

Animated.CompositeAnimation.start(animation, ~callback=_didFinish => (), ());
```

### calculation

You can combine two animated values via addition, multiplication, division, or modulo to make a new animated value.

The following example demonstrates use of `Animated.multiply` in order to reverse the value of the `animatedValue`.

```reason
open Rebolt;

let animatedValue = Animated.Value.create(0.0);

let newAnimatedValue = Animated.multiply(animatedValue, Animated.Value.create(-1.0));
```

Keep in mind that calculated values (such as `newAnimatedValue` from the snippet above) cannot be animated. Trying to pass them to any of the animated functions will result in a type error.

### interpolation

You can interpolate an animated value in order to bind to its value and change the output.

The following example demonstrates interpolation in order to map values of an animated value to the opacity of a container.

```reason
let animatedValue = Animated.Value.create(100.0);

let animatedOpacity =
	Animated.Value.interpolate(
		animatedValue,
		~inputRange=[0.0, 100.0],
		~outputRange=`float([0.0, 1.0]),
		~extrapolate=Animated.Interpolation.Clamp,
		(),
	);
```

### styling

Animated values can be passed to an animated component in order to change its apperance as the animated value changes.

The example below demonstrates animating opacity of a component.

```reason
open Rebolt;

let animatedValue = Animated.Value.create(0.0);

let component = ReasonReact.statelessComponent("MyComponent");

let containerStyle = Style.(
	style([
	  opacity(Animated(animatedValue))
		flex(1.0)
	])
);

let make = _children => {
  ...component,
	didMount: _self => {
		Animated.CompositeAnimation.start(
			Animated.Timing.animate(
				~value=animatedValue,
				~toValue=`raw(1.0),
				~duration=100.0,
				(),
			),
			~callback=_didFinish => (),
			()
		);
	},
  render: _self => <Animated.View style=containerStyle />,
};
```
