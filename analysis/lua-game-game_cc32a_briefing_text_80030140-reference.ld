/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc32a_briefing_text_80030140)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__21cc32a_String_803426b8 = 0x803426b8;
cc32a_error_80373088 = 0x80373088;
cc32a_key_803730b0 = 0x803730b0;
fn_80030260 = 0x80030260;
fn_800306a4 = 0x800306a4;
fn_800fc2b0 = 0x800fc2b0;
fn_800fc550 = 0x800fc550;
fn_80165254 = 0x80165254;
fn_80178d1c = 0x80178d1c;
fn_80179170 = 0x80179170;
fn_8020c510 = 0x8020c510;
fn_8020c5c4 = 0x8020c5c4;
fn_80341588 = 0x80341588;
SECTIONS {
  .text.cc32a_briefing_text_80030140 0x80030140 : { *(.text.cc32a_briefing_text_80030140) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
