We can see that there's nothing interesting in `/index.html`.

By fuzzing with different filenames, we find `/robots.txt` that contains:

```
User-agent: *
Disallow: /hidden_folder/flag.txt
```

By visiting `/hidden_folder/flag.txt`, we get the flag.

Flag: `ctf{I_am_a_robot}`