/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc17c_sinit_8018bc18)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__16W3dType_8020fbd0PvN21ii = 0x8020fbd0;
fn_801899d4 = 0x801899d4;
lbl_80361c58 = 0x80361c58;
lbl_80361f58 = 0x80361f58;
lbl_803e8aa8 = 0x803e8aa8;
SECTIONS {
  .text.w3d_cc17c_sinit_8018bc18 0x8018bc18 : { *(.text.w3d_cc17c_sinit_8018bc18) }
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
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
