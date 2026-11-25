/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc20a_choose_actor_release_80159538)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800fc43c = 0x800fc43c;
fn_80161050 = 0x80161050;
lbl_803a3fd0 = 0x803a3fd0;
lbl_80410f80 = 0x80410f80;
SECTIONS {
  .text.w3d_cc20a_choose_actor_release_80159538 0x80159538 : { *(.text.w3d_cc20a_choose_actor_release_80159538) }
  .sdata 0x804ab40c (NOLOAD) : {
    . = 0x0; lbl_804ab40c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
