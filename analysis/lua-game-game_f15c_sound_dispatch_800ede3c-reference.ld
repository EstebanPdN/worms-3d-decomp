/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f15c_sound_dispatch_800ede3c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lookup_80164fc8 = 0x80164fc8;
pair0_800edc28 = 0x800edc28;
pair1_800edca0 = 0x800edca0;
read_800fc330 = 0x800fc330;
single_800edd1c = 0x800edd1c;
type_80367b08 = 0x80367b08;
type_80367ba8 = 0x80367ba8;
type_80367bf8 = 0x80367bf8;
SECTIONS {
  .text.f15c_sound_dispatch_800ede3c 0x800ede3c : { *(.text.f15c_sound_dispatch_800ede3c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
