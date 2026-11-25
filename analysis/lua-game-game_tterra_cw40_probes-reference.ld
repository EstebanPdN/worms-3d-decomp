/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(tterra_cw40_wrap_80322ce0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802fdb6c = 0x802fdb6c;
fn_802fdb80 = 0x802fdb80;
fn_803345bc = 0x803345bc;
fn_803345f0 = 0x803345f0;
fn_80334840 = 0x80334840;
fn_80334c80 = 0x80334c80;
fn_80334f84 = 0x80334f84;
fn_80335440 = 0x80335440;
fn_80335580 = 0x80335580;
fn_8033dcf0 = 0x8033dcf0;
fn_8033de40 = 0x8033de40;
SECTIONS {
  .text.tterra_cw40_wrap_80322ce0 0x80322ce0 : { *(.text.tterra_cw40_wrap_80322ce0) }
  .text.tterra_cw40_wrap_80322d00 0x80322d00 : { *(.text.tterra_cw40_wrap_80322d00) }
  .text.tterra_cw40_wrap_80328694 0x80328694 : { *(.text.tterra_cw40_wrap_80328694) }
  .text.tterra_cw40_wrap_8033457c 0x8033457c : { *(.text.tterra_cw40_wrap_8033457c) }
  .text.tterra_cw40_wrap_8033459c 0x8033459c : { *(.text.tterra_cw40_wrap_8033459c) }
  .text.tterra_cw40_wrap_80334758 0x80334758 : { *(.text.tterra_cw40_wrap_80334758) }
  .text.tterra_cw40_wrap_80334778 0x80334778 : { *(.text.tterra_cw40_wrap_80334778) }
  .text.tterra_cw40_wrap_80334840 0x80334840 : { *(.text.tterra_cw40_wrap_80334840) }
  .text.tterra_cw40_wrap_80334978 0x80334978 : { *(.text.tterra_cw40_wrap_80334978) }
  .text.tterra_cw40_flags_80335720 0x80335720 : { *(.text.tterra_cw40_flags_80335720) }
  .text.tterra_cw40_wrap_80335b30 0x80335b30 : { *(.text.tterra_cw40_wrap_80335b30) }
  .text.tterra_cw40_wrap_80335b50 0x80335b50 : { *(.text.tterra_cw40_wrap_80335b50) }
  .sdata 0x804b1680 (NOLOAD) : {
    . = 0x0; lbl_804b1680 = .;
    . = 0x10; lbl_804b1690 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
