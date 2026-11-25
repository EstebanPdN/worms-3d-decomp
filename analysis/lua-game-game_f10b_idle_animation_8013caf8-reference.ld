/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f10b_idle_animation_8013caf8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
aim_80181884 = 0x80181884;
amount_8013c844 = 0x8013c844;
blend_8039f940 = 0x8039f940;
clear_801817e0 = 0x801817e0;
fade_80181814 = 0x80181814;
grenade_8039f92c = 0x8039f92c;
headers_8039f91c = 0x8039f91c;
neutral_8039f3b8 = 0x8039f3b8;
pigeon_8039f3ac = 0x8039f3ac;
play_801359ec = 0x801359ec;
random_80162c20 = 0x80162c20;
rate_8039f93c = 0x8039f93c;
zero_8039f944 = 0x8039f944;
SECTIONS {
  .text.f10b_idle_animation_8013caf8 0x8013caf8 : { *(.text.f10b_idle_animation_8013caf8) }
  .sdata 0x804ab100 (NOLOAD) : {
    . = 0x0; name_804ab100 = .;
    . = 0x150; name_804ab250 = .;
    . = 0x154; name_804ab254 = .;
    . = 0x158; name_804ab258 = .;
    . = 0x15c; name_804ab25c = .;
    . = 0x160; name_804ab260 = .;
    . = 0x164; name_804ab264 = .;
    . = 0x168; name_804ab268 = .;
    . = 0x16c; name_804ab26c = .;
    . = 0x170; name_804ab270 = .;
    . = 0x174; name_804ab274 = .;
    . = 0x178; name_804ab278 = .;
    . = 0x17c; name_804ab27c = .;
    . = 0x180; name_804ab280 = .;
    . = 0x184; name_804ab284 = .;
    . = 0x188; name_804ab288 = .;
    . = 0x18c; name_804ab28c = .;
    . = 0x190; name_804ab290 = .;
    . = 0x194; name_804ab294 = .;
    . = 0x198; name_804ab298 = .;
    . = 0x19c; name_804ab29c = .;
    . = 0x1a0; name_804ab2a0 = .;
    . = 0x22c; name_804ab32c = .;
    . = 0x6688; context_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
