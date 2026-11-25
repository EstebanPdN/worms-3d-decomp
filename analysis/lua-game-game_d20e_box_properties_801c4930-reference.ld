/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d20e_register_box_properties_801c4930)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801ebf38 = 0x801ebf38;
fn_801efec4 = 0x801efec4;
fn_801f0504 = 0x801f0504;
k_803aca60 = 0x803aca60;
k_803aca84 = 0x803aca84;
k_803acab0 = 0x803acab0;
k_803acae0 = 0x803acae0;
k_803acb10 = 0x803acb10;
lbl_803aca0c = 0x803aca0c;
lbl_8045ed7c = 0x8045ed7c;
memset = 0x802eefe0;
value_803acb38 = 0x803acb38;
SECTIONS {
  .text.w3d_d20e_register_box_properties_801c4930 0x801c4930 : { *(.text.w3d_d20e_register_box_properties_801c4930) }
  .bss 0x8045d610 : { *(.bss) }
  .sbss 0x804b04d4 : { *(.sbss) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
