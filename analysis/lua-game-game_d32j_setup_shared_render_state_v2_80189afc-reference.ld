/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d32j_setup_shared_render_state_v2_80189afc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801902e8 = 0x801902e8;
fn_8020b680 = 0x8020b680;
lbl_803a7c40 = 0x803a7c40;
lbl_803a7c54 = 0x803a7c54;
lbl_803a7c58 = 0x803a7c58;
type_80413db0 = 0x80413db0;
type_80414210 = 0x80414210;
type_80414260 = 0x80414260;
type_80415bb0 = 0x80415bb0;
type_80415c00 = 0x80415c00;
type_80415c10 = 0x80415c10;
type_80415c30 = 0x80415c30;
type_80415c80 = 0x80415c80;
type_80415cb0 = 0x80415cb0;
type_804166b0 = 0x804166b0;
type_80416750 = 0x80416750;
vt_80412ee0 = 0x80412ee0;
SECTIONS {
  .text.d32j_setup_shared_render_state_v2_80189afc 0x80189afc : { *(.text.d32j_setup_shared_render_state_v2_80189afc) }
  .sdata 0x804b0238 (NOLOAD) : {
    . = 0x0; lbl_804b0238 = .;
    . = 0x4; lbl_804b023c = .;
    . = 0x8; lbl_804b0240 = .;
    . = 0xc; lbl_804b0244 = .;
    . = 0x10; lbl_804b0248 = .;
    . = 0x14; lbl_804b024c = .;
    . = 0x18; lbl_804b0250 = .;
    . = 0x1c; lbl_804b0254 = .;
    . = 0x20; lbl_804b0258 = .;
    . = 0x24; lbl_804b025c = .;
    . = 0x28; lbl_804b0260 = .;
    . = 0x2c; lbl_804b0264 = .;
    . = 0x30; lbl_804b0268 = .;
    . = 0x34; lbl_804b026c = .;
    . = 0x1670; lbl_804b18a8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
