/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s9_initialize_shared_properties_80172a0c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__16S9RegisteredTypePcT1PFv_vii = 0x8020fbd0;
fn_8016fb54 = 0x8016fb54;
fn_8018330c = 0x8018330c;
fn_80186a34 = 0x80186a34;
lbl_80361b08 = 0x80361b08;
lbl_80361bf8 = 0x80361bf8;
lbl_80361c28 = 0x80361c28;
lbl_80361f58 = 0x80361f58;
lbl_803e89c8 = 0x803e89c8;
lbl_803e8a70 = 0x803e8a70;
lbl_803e8a8c = 0x803e8a8c;
SECTIONS {
  .text.s9_initialize_shared_properties_80172a0c 0x80172a0c : { *(.text.s9_initialize_shared_properties_80172a0c) }
  .text.s9_initialize_shared_properties_80184fe4 0x80184fe4 : { *(.text.s9_initialize_shared_properties_80184fe4) }
  .text.s9_initialize_shared_properties_8018893c 0x8018893c : { *(.text.s9_initialize_shared_properties_8018893c) }
  .sdata 0x804b0124 (NOLOAD) : {
    . = 0x0; lbl_804b0124 = .;
    . = 0x4; lbl_804b0128 = .;
    . = 0x8; lbl_804b012c = .;
    . = 0xc; lbl_804b0130 = .;
    . = 0x10; lbl_804b0134 = .;
    . = 0x14; lbl_804b0138 = .;
    . = 0x18; lbl_804b013c = .;
    . = 0x1c; lbl_804b0140 = .;
    . = 0x20; lbl_804b0144 = .;
    . = 0x24; lbl_804b0148 = .;
    . = 0x28; lbl_804b014c = .;
    . = 0x2c; lbl_804b0150 = .;
    . = 0xb0; lbl_804b01d4 = .;
    . = 0xb4; lbl_804b01d8 = .;
    . = 0xb8; lbl_804b01dc = .;
    . = 0xbc; lbl_804b01e0 = .;
    . = 0xc0; lbl_804b01e4 = .;
    . = 0xc4; lbl_804b01e8 = .;
    . = 0xc8; lbl_804b01ec = .;
    . = 0xcc; lbl_804b01f0 = .;
    . = 0xd0; lbl_804b01f4 = .;
    . = 0xd4; lbl_804b01f8 = .;
    . = 0xd8; lbl_804b01fc = .;
    . = 0xdc; lbl_804b0200 = .;
    . = 0xe0; lbl_804b0204 = .;
    . = 0xe4; lbl_804b0208 = .;
    . = 0xe8; lbl_804b020c = .;
    . = 0xec; lbl_804b0210 = .;
    . = 0xf0; lbl_804b0214 = .;
    . = 0xf4; lbl_804b0218 = .;
    . = 0xf8; lbl_804b021c = .;
    . = 0xfc; lbl_804b0220 = .;
    . = 0x100; lbl_804b0224 = .;
    . = 0x104; lbl_804b0228 = .;
    . = 0x108; lbl_804b022c = .;
    . = 0x10c; lbl_804b0230 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
