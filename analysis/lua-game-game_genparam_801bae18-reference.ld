/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_property_register_extra_801bae18)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801eff8c = 0x801eff8c;
memset = 0x802eefe0;
w3d_descriptor_8045e004 = 0x8045e004;
w3d_extra_803fe540 = 0x803fe540;
w3d_extra_803fe624 = 0x803fe624;
w3d_extra_80400814 = 0x80400814;
w3d_extra_80400820 = 0x80400820;
w3d_extra_8040082c = 0x8040082c;
w3d_extra_80400b60 = 0x80400b60;
w3d_extra_80400b78 = 0x80400b78;
w3d_extra_80400b84 = 0x80400b84;
w3d_extra_80400b90 = 0x80400b90;
w3d_extra_80400b9c = 0x80400b9c;
w3d_extra_80400ba8 = 0x80400ba8;
w3d_extra_80400bf0 = 0x80400bf0;
w3d_property_8045d0fc = 0x8045d0fc;
w3d_property_8045d804 = 0x8045d804;
w3d_property_80464b1c = 0x80464b1c;
w3d_property_80464b30 = 0x80464b30;
w3d_property_80464b44 = 0x80464b44;
w3d_property_80464b6c = 0x80464b6c;
w3d_property_80464b80 = 0x80464b80;
w3d_property_80464b94 = 0x80464b94;
w3d_property_80464ba8 = 0x80464ba8;
w3d_property_80464bbc = 0x80464bbc;
w3d_property_80464bd0 = 0x80464bd0;
w3d_property_80464c48 = 0x80464c48;
w3d_string_803ab620 = 0x803ab620;
w3d_string_803ad844 = 0x803ad844;
w3d_string_803ba528 = 0x803ba528;
w3d_string_803ba544 = 0x803ba544;
w3d_string_803ba72c = 0x803ba72c;
w3d_string_803bab34 = 0x803bab34;
w3d_string_803bac10 = 0x803bac10;
w3d_string_803baeb4 = 0x803baeb4;
w3d_string_803bb048 = 0x803bb048;
w3d_string_803bb0b0 = 0x803bb0b0;
w3d_string_803bb110 = 0x803bb110;
w3d_string_803bbd64 = 0x803bbd64;
SECTIONS {
  .text.w3d_property_register_extra_801bae18 0x801bae18 : { *(.text.w3d_property_register_extra_801bae18) }
  .text.w3d_property_register_extra_801cea94 0x801cea94 : { *(.text.w3d_property_register_extra_801cea94) }
  .text.w3d_property_register_extra_8022bf14 0x8022bf14 : { *(.text.w3d_property_register_extra_8022bf14) }
  .text.w3d_property_register_extra_8022c168 0x8022c168 : { *(.text.w3d_property_register_extra_8022c168) }
  .text.w3d_property_register_extra_8022cd14 0x8022cd14 : { *(.text.w3d_property_register_extra_8022cd14) }
  .text.w3d_property_register_extra_80235f98 0x80235f98 : { *(.text.w3d_property_register_extra_80235f98) }
  .text.w3d_property_register_extra_8023652c 0x8023652c : { *(.text.w3d_property_register_extra_8023652c) }
  .text.w3d_property_register_extra_80236ccc 0x80236ccc : { *(.text.w3d_property_register_extra_80236ccc) }
  .text.w3d_property_register_extra_802372b0 0x802372b0 : { *(.text.w3d_property_register_extra_802372b0) }
  .text.w3d_property_register_extra_80237818 0x80237818 : { *(.text.w3d_property_register_extra_80237818) }
  .text.w3d_property_register_extra_80237d78 0x80237d78 : { *(.text.w3d_property_register_extra_80237d78) }
  .text.w3d_property_register_extra_8023b414 0x8023b414 : { *(.text.w3d_property_register_extra_8023b414) }
  .sdata 0x804b03d0 (NOLOAD) : {
    . = 0x0; w3d_property_guard_804b03d0 = .;
    . = 0x168; w3d_property_guard_804b0538 = .;
    . = 0x434; w3d_property_guard_804b0804 = .;
    . = 0x438; w3d_property_guard_804b0808 = .;
    . = 0x43c; w3d_property_guard_804b080c = .;
    . = 0x444; w3d_property_guard_804b0814 = .;
    . = 0x448; w3d_property_guard_804b0818 = .;
    . = 0x44c; w3d_property_guard_804b081c = .;
    . = 0x450; w3d_property_guard_804b0820 = .;
    . = 0x454; w3d_property_guard_804b0824 = .;
    . = 0x458; w3d_property_guard_804b0828 = .;
    . = 0x46c; w3d_property_guard_804b083c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
