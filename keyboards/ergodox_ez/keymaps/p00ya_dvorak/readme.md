# ErgoDox EZ Dvorak software remap

This is a Dvorak layout I use for coding on a Macbook.  It should work fine for other platforms too.  I think it's a good layout for people transitioning to Ergodox from traditional (US-layout) keyboard hardware.

**It's designed for US-layout keyboards being software-remapped to Dvorak.** When the Ergodox sends `D`, I'm assuming your UI/terminal inserts `E`.  I do this because it makes it easy to switch to other US-layout keyboard hardware (like the built-in Macbook keyboard) while still typing in Dvorak.

My philosophy in designing this layout is:

* follow Apple & Dvorak layouts where possible (but remove caps-lock!)
* make symbols like brackets convenient (particularly for C code)
* ring/pinky finger reaches are OK
* long thumb reaches are inconvenient
* it's okay to have inconvenient keys if they have convenient software equivalents (like `^d` for `⌦`)
* have "full size keyboard" layouts available as layers

## Base Layer

The Base layer positions keys as close as possible to where they'd be on a (US-layout) Apple keyboard.  You *can* try and use this as a QWERTY layout without software remapping, though the Coding Layer (required for brackets) won't seem logical.  It also means you need to think of the physical keyboard as a QWERTY keyboard when using it for things that don't apply the software-remap (like Linux's Magic SysRq commands).

Now, assuming you are software-remapping to Dvorak, the notable differences are:

* the physical caps lock key sends `esc`/`control`; there is no `caps lock`.
* `return` is on the left thumb cluster
* stretched right-pinky keys (`=`, `\` and brackets) are all missing; they're on the Coding Layer
* `6` is on the left hand, and `7` is directly above `G`

## Additional Layers

All the alpha-numeric keys are on the Base Layer, with some missing symbols are on the Coding Layer.  There are also convenience layers for the numpad, dirpad (10)

1. Numpad: on the right hand, with `num 5` where `N` is on the base layer.
2. Dirpad: on the right hand, with `⌦` where `H` is on the base layer).  Moves the arrow keys to the bottom right, and adds in the right-hand `control` and `alt` modifiers.
4. Coding: activated by holding the left `space` key; adds many of the missing pinky keys onto the right hand, including `{}[]()=+\|`, and applies a shift modifier to the number keys (for `!@#` etc.).  Left-hand modifiers are duplicated onto the home row since the thumb is needed for the layer.
5. Steno: "QWERTY" layout for stenography (e.g. Plover), but with pinky keys shifted down a row and thumb keys on the actual thumb cluster.  Also activates NKRO.
6. Function: function keys on the top row, media keys below them, and Apple `fn`-modified equivalents for some other keys.  Also shows num/scroll/caps lock and NKRO status via LED brightness.

## Download

Download a compiled copy from: 
https://drive.google.com/uc?id=1twyb2AlcK5QeWFsg4lUtIF3IZhyC3aE9&export=download

The layout in this keymap is duplicated in Oryx at https://configure.ergodox-ez.com/ergodox-ez/layouts/vAdRO/latest/0.  This means you can view the key layouts using the Oryx software.  Additionally, this branch includes WebUSB support, so it will work with the Oryx training software.

There are some special features in this keymap (like control of the LEDs and NKRO) that are *not* supported by Oryx.  Therefore, I don't recommend downloading the source or firmware from the Oryx site.

## macOS Keyboard Panel

The base layout can be displayed as a custom panel in the macOS Accessibility Keyboard (AKA the "Keyboard Viewer").  Import the `p00yaErgodox.ascconfig` bundle using the
[macOS Panel Editor](https://support.apple.com/en-us/guide/mac-help/mh43606/mac).
