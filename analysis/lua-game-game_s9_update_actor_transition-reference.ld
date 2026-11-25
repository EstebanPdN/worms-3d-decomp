/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s9_update_actor_transition_8013c9ac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801359EC = 0x801359ec;
fn_80138DAC = 0x80138dac;
fn_80139234 = 0x80139234;
fn_8013D440 = 0x8013d440;
fn_80165254 = 0x80165254;
fn_801817E0 = 0x801817e0;
lbl_8039F910 = 0x8039f910;
lbl_8039F914 = 0x8039f914;
lbl_8039F918 = 0x8039f918;
SECTIONS {
  .text.s9_update_actor_transition_8013c9ac 0x8013c9ac : { *(.text.s9_update_actor_transition_8013c9ac) }
  .sdata 0x804ab100 (NOLOAD) : {
    . = 0x0; lbl_804AB100 = .;
    . = 0x228; lbl_804AB328 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
