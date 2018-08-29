You are given a image:

![problem image](./image.png?raw=true "A harmless-looking image")

Because a image can be represented as hex, we can look for certain file headers in the hex dump.

```
❯ binwalk image.png

DECIMAL       HEXADECIMAL     DESCRIPTION
--------------------------------------------------------------------------------
0             0x0             PNG image, 400 x 400, 8-bit/color RGB, non-interlaced
105026        0x19A42         Zip archive data, at least v2.0 to extract, name: flag.txt
105185        0x19AE1         End of Zip archive
```

We can see that there is a zip file embedded in the PNG image. Let's extract it:

```
❯ binwalk -e image.png
❯ ls _image.png.extracted
19A42.zip flag.txt
❯ cat _image.png.extracted/flag.txt
ctf{flag_in_a_image}
```

Flag: `ctf{flag_in_a_image}`