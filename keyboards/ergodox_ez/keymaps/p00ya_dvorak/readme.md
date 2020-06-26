# ErgoDox EZ Dvorak software remap

This is a Dvorak layout I use for coding on a Macbook.  It should work fine for other platforms too.  I think it's a good layout for people transitioning to Ergodox from traditional (US-layout) keyboard hardware.

**It's designed for US-layout keyboards being software-remapped to Dvorak.** When the Ergodox sends `D`, I'm assuming your UI/terminal inserts `E`.  I do this because it makes it easy to switch to other US-layout keyboard hardware (like the built-in Macbook keyboard) while still typing in Dvorak.

My philosophy in designing this layout is:

* follow Apple & Dvorak layouts where possible (but remove caps-lock!)
* don't require layer switches for typing text
* make symbols like brackets convenient (for code)
* ring/pinky finger reaches are OK
* long thumb reaches are inconvenient
* it's okay to have inconvenient keys if they have convenient software equivalents (like `^d` for `⌦`)
* have "full size keyboard" layouts available as layers

## Base Layer

The Base layer positions keys as close as possible to where they'd be on a (US-layout) Apple keyboard.  You *can* try and use this as a QWERTY layout without software remapping, but things like bracket placements won't seem logical.  It also means you need to think of the physical keyboard as a QWERTY keyboard when using it for things that don't apply the software-remap (like Linux's Magic SysRq commands).

Now, assuming you are software-remapping to Dvorak, the notable differences are:

* the physical caps lock key sends `esc`/`control`; there is no `caps lock`.
* shift keys are also `[` square brackets `]` when tapped
* `{` brace brackets `}` are on the thumbs
* `return` is on the right thumb cluster
* `space` is on the left thumb cluster (and also the mod-tap `⌘` keys)
* `=` and `\` get wrapped around from the right pinky to the right forefinger
* `6` is on the left hand, and `7` is directly above `G`

## Shifting and Tapping Options

Number keys have auto-shift enabled (pressing `1` for at least 175ms will send `!` when released).

`PERMISSIVE_HOLD` and `IGNORE_MOD_TAP_INTERRUPT` are enabled.  The QMK documentation on these is extremely misleading, so here are some examples:

* `⇧` down, `q` tap, `⇧` up, all in 180ms, will send `Q` (i.e. `⇧q`)
* `⇧` down, `q` down, `⇧` up, all in 180ms, will send `[` `q`
* `⇧` down, `q` down, without releasing either for 180ms, will send `Q`
* `q` down, `⇧` down, will send `q` `[`
* `⇧` held for more than 180ms will never send `[`

Because many of the modifiers are dual-function keys (send a "regular", non-modifier key when tapped), it's worth knowing that you can repeat the regular key using tap-and-hold: tapping it <180ms before holding it.

## Additional Layers

While everything you need for typing code & prose is on the Base Layer, some additional layers are defined for convenience:

1. Numpad: on the right hand, with `num 5` where `N` is on the base layer.
2. Dirpad: on the right hand, with `⌦` where `H` is on the base layer).  Also places mousekeys on the left hand in an `ESDF`-style configuration.
3. Function: function keys on the top row, media keys below them, and Apple `fn`-modified equivalents for some other keys.  Also includes a Linux Magic SysRq "EISUB" macro key on the left thumb cluster.
4. Brackets: shifts the right hand number-keys left, to make room for brackets in their usual Dvorak position between `0` and `⌫`.
