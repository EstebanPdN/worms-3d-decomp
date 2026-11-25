/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24g_bank_key_80051234)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__4TextPCcUiUi = 0x8020bbec;
bank_select_800fd4c8 = 0x800fd4c8;
load_menu_80050aa0 = 0x80050aa0;
page_setup_8004fe48 = 0x8004fe48;
strchr = 0x802ef198;
string_finish_8020c5c4 = 0x8020c5c4;
string_release_80341588 = 0x80341588;
upper_8020c2e8 = 0x8020c2e8;
SECTIONS {
  .text.w3d_d24g_bank_key_80051234 0x80051234 : { *(.text.w3d_d24g_bank_key_80051234) }
  .sdata 0x804aa9fc (NOLOAD) : {
    . = 0x0; keys_804aa9fc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
