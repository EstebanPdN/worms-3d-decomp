/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_80015d40)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8001523C = 0x8001523c;
fn_800E5BB8 = 0x800e5bb8;
fn_8015FEF0 = 0x8015fef0;
fn_8018E26C = 0x8018e26c;
fn_801FE160 = 0x801fe160;
fn_80212FD4 = 0x80212fd4;
fn_802134FC = 0x802134fc;
fn_80213C30 = 0x80213c30;
fn_802AFB20 = 0x802afb20;
fn_803426B8 = 0x803426b8;
lbl_803B3080 = 0x803b3080;
lbl_804130C0 = 0x804130c0;
lbl_8041C7D0 = 0x8041c7d0;
lbl_8041C820 = 0x8041c820;
SECTIONS {
  .text.w3d_auto_80015d40 0x80015d40 : { *(.text.w3d_auto_80015d40) }
  .text.w3d_auto_80060088 0x80060088 : { *(.text.w3d_auto_80060088) }
  .text.w3d_auto_8013f57c 0x8013f57c : { *(.text.w3d_auto_8013f57c) }
  .text.w3d_auto_801626c8 0x801626c8 : { *(.text.w3d_auto_801626c8) }
  .text.w3d_auto_801676e0 0x801676e0 : { *(.text.w3d_auto_801676e0) }
  .text.w3d_auto_8016f8a0 0x8016f8a0 : { *(.text.w3d_auto_8016f8a0) }
  .text.w3d_auto_801788e4 0x801788e4 : { *(.text.w3d_auto_801788e4) }
  .text.w3d_auto_8018ef3c 0x8018ef3c : { *(.text.w3d_auto_8018ef3c) }
  .text.w3d_auto_801d67e4 0x801d67e4 : { *(.text.w3d_auto_801d67e4) }
  .text.w3d_auto_80208fd8 0x80208fd8 : { *(.text.w3d_auto_80208fd8) }
  .text.w3d_auto_80209030 0x80209030 : { *(.text.w3d_auto_80209030) }
  .text.w3d_auto_8020b138 0x8020b138 : { *(.text.w3d_auto_8020b138) }
  .text.w3d_auto_802ba3fc 0x802ba3fc : { *(.text.w3d_auto_802ba3fc) }
  .text.w3d_auto_802e0c78 0x802e0c78 : { *(.text.w3d_auto_802e0c78) }
  .text.w3d_auto_80358118 0x80358118 : { *(.text.w3d_auto_80358118) }
  .text.w3d_auto_80359cd8 0x80359cd8 : { *(.text.w3d_auto_80359cd8) }
  .sdata 0x804aa6f8 (NOLOAD) : {
    . = 0x0; lbl_804AA6F8 = .;
    . = 0x4; lbl_804AA6FC = .;
    . = 0x8; lbl_804AA700 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
