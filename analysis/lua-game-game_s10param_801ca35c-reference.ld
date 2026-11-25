/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s10_register_two_arrays_801ca35c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801efdfc = 0x801efdfc;
fn_801efe60 = 0x801efe60;
fn_801efec4 = 0x801efec4;
fn_801f2420 = 0x801f2420;
fn_801f25b0 = 0x801f25b0;
lbl_803adc88 = 0x803adc88;
lbl_803adc94 = 0x803adc94;
lbl_803bb27c = 0x803bb27c;
lbl_803bbdc8 = 0x803bbdc8;
lbl_803bbe08 = 0x803bbe08;
lbl_803bbe2c = 0x803bbe2c;
lbl_8045d69c = 0x8045d69c;
lbl_8045d6b0 = 0x8045d6b0;
lbl_8045e29c = 0x8045e29c;
lbl_8045e47c = 0x8045e47c;
lbl_8045ed4c = 0x8045ed4c;
lbl_8045ed58 = 0x8045ed58;
lbl_8045ed7c = 0x8045ed7c;
lbl_80464c5c = 0x80464c5c;
lbl_80464c70 = 0x80464c70;
lbl_80464cac = 0x80464cac;
lbl_80464cc0 = 0x80464cc0;
lbl_80464ce8 = 0x80464ce8;
lbl_80464cfc = 0x80464cfc;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_s10_register_two_arrays_801ca35c 0x801ca35c : { *(.text.w3d_s10_register_two_arrays_801ca35c) }
  .text.w3d_s10_register_two_arrays_8023b840 0x8023b840 : { *(.text.w3d_s10_register_two_arrays_8023b840) }
  .text.w3d_s10_register_two_arrays_8023c004 0x8023c004 : { *(.text.w3d_s10_register_two_arrays_8023c004) }
  .text.w3d_s10_register_two_arrays_8023c578 0x8023c578 : { *(.text.w3d_s10_register_two_arrays_8023c578) }
  .sdata 0x804b04f0 (NOLOAD) : {
    . = 0x0; lbl_804b04f0 = .;
    . = 0x4; lbl_804b04f4 = .;
    . = 0x350; lbl_804b0840 = .;
    . = 0x354; lbl_804b0844 = .;
    . = 0x360; lbl_804b0850 = .;
    . = 0x364; lbl_804b0854 = .;
    . = 0x36c; lbl_804b085c = .;
    . = 0x370; lbl_804b0860 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
