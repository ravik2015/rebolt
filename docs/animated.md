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

### Animations

Animated provides three types of animation types. Each animation type provides a particular animation curve that controls how your values animate from their initial value to the final value.

### Configuration

Below is the list of common configuration options applicable to all below animations.

#### toValue

```reason
~toValue: [ | `raw(float) | `animated(Animated.value))]
```

#### value

```reason
~value: Animated.value
```

#### useNativeDriver

```reason
~useNativeDriver: bool=?
```

#### iterations

```reason
~iterations: int=?
```

### Spring

Provides a simple spring physics model.

```reason
let animation = Animated.Spring.animate(
	~value=animatedValue,
	~toValue=`raw(1.0),
	~bounciness=5.0,
	(),
);
```

See available configuration below:

#### restDisplacementThreshold

```reason
~restDisplacementThreshold: float=?
```

#### overshootClamping

```reason
~overshootClamping: bool=?
```

#### restSpeedThreshold

```reason
~restSpeedThreshold: float=?
```

#### velocity

```reason
~velocity: float=?
```

#### bounciness

```reason
~bounciness: float=?
```

#### speed

```reason
~speed: float=?
```

#### tension

```reason
~tension: float=?
```

#### friction

```reason
~friction: float=?
```

#### stiffness

```reason
~stiffness: float=?
```

#### mass

```reason
~mass: float=?
```

#### damping

```reason
~damping: float=?
```

### Timing

### Decay

## Composition

### parallel

### stagger

### delay

### sequence

### loop

## Animated.Value

### create

### add

### divide

### multiply

### diffClamp

### modulo

### interpolate

### setValue

### setOffset

### flattenOffset

### extractOffset

### addListener

### removeListener

### removeAllListeners

### stopTracking

### track

## CompositeAnimation

### start

### stop

### reset

## Easing

This module is exposed under `Animated` for historical reasons. Please see [`Easing`](/docs/easing.html) module instead.
