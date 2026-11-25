/* Original addresses observed in GWMP8P. This links only the RNG slice. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(fn_80162BA8)

_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;

SECTIONS
{
    .text 0x80162ba8 : { *(.text) }
    .rodata 0x803a4a28 : { *(.rodata) }
    .sbss 0x804b00c4 (NOLOAD) :
    {
        lbl_804B00C4 = .;
        . += 4;
        lbl_804B00C8 = .;
        . += 4;
    }
    /DISCARD/ : { *(.comment) }
}
