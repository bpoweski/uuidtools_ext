UUIDTools Ext
================================

A faster version of https://github.com/sporkmonger/uuidtools that aims for compatibility.

uuidtools
=================================

```bash

$ rake benchmark
16751.9339812355 version 1 per second.
10612.0728501167 version 3 per second.
10276.3410155298 version 4 per second.
10658.4590113611 version 5 per second.
```

uuidtools_ext
=================================

```bash

$ bundle exec rake benchmark
24152.7791534126 version 1 per second.
31492.1969733942 version 3 per second.
12198.6768565061 version 4 per second.
35412.1236784738 version 5 per second.
```
