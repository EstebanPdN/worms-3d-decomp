/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8002fb9c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8002FCD0 = 0x8002fcd0;
fn_8003013C = 0x8003013c;
fn_80030140 = 0x80030140;
fn_8006E71C = 0x8006e71c;
fn_8010A8FC = 0x8010a8fc;
fn_8015F65C = 0x8015f65c;
fn_8015FB34 = 0x8015fb34;
fn_802EF234 = 0x802ef234;
lbl_80372FC0 = 0x80372fc0;
SECTIONS {
  .text.w3d_auto_8002fb9c 0x8002fb9c : { *(.text.w3d_auto_8002fb9c) }
  .sdata 0x804acd4c (NOLOAD) : {
    . = 0x0; lbl_804ACD4C = .;
    . = 0x8; lbl_804ACD54 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
