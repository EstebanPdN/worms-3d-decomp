/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_f6a_advance_menu_8028e9c0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__13Text_803426b8 = 0x803426b8;
briefing_803d0038 = 0x803d0038;
empty_803d0034 = 0x803d0034;
fn_8006e71c = 0x8006e71c;
fn_800c4660 = 0x800c4660;
fn_800c4a7c = 0x800c4a7c;
fn_800fc1f0 = 0x800fc1f0;
fn_800fc2b0 = 0x800fc2b0;
fn_800fc550 = 0x800fc550;
fn_8015ccbc = 0x8015ccbc;
fn_8020c5c0 = 0x8020c5c0;
fn_8020c5c4 = 0x8020c5c4;
fn_8028e630 = 0x8028e630;
fn_802ef234 = 0x802ef234;
fn_80341588 = 0x80341588;
fn_80341884 = 0x80341884;
fn_8035eec4 = 0x8035eec4;
refcount_803d001c = 0x803d001c;
SECTIONS {
  .text.w3d_f6a_advance_menu_8028e9c0 0x8028e9c0 : { *(.text.w3d_f6a_advance_menu_8028e9c0) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; app_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
