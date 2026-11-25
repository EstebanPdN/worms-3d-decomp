/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(_._13F1pAudioOwner)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._21F1pAudioBase_801628ec = 0x801628ec;
fn_8020c5c4 = 0x8020c5c4;
fn_80341588 = 0x80341588;
vt_8041bbc0 = 0x8041bbc0;
SECTIONS {
  .text._._13F1pAudioOwner 0x80260a24 : { *(.text._._13F1pAudioOwner) }
  .sdata 0x804abb44 (NOLOAD) : {
    . = 0x0; instance_804abb44 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
