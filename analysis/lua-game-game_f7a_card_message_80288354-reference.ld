/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_f7a_card_message_80288354)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
boot_803cf8b8 = 0x803cf8b8;
fn_8015f65c = 0x8015f65c;
fn_8016293c = 0x8016293c;
fn_80288ab8 = 0x80288ab8;
fn_80288b9c = 0x80288b9c;
fn_80289da4 = 0x80289da4;
fn_80289df8 = 0x80289df8;
fn_80289e80 = 0x80289e80;
fn_802fb7ac = 0x802fb7ac;
load_803cf8e4 = 0x803cf8e4;
save_803cf8d0 = 0x803cf8d0;
SECTIONS {
  .text.w3d_f7a_card_message_80288354 0x80288354 : { *(.text.w3d_f7a_card_message_80288354) }
  .sdata 0x804b0c14 (NOLOAD) : {
    . = 0x0; cache_804b0c14 = .;
    . = 0x8; cache_804b0c1c = .;
    . = 0x10; cache_804b0c24 = .;
    . = 0x18; cache_804b0c2c = .;
    . = 0x20; cache_804b0c34 = .;
    . = 0x28; cache_804b0c3c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
