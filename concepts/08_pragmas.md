# Pragmas

## Pragma once

I modern compilers the processor directive pragma once can be used to repalce
the guards ifdefs.

```C++
#pragma once
```

Old include guards

```C++
#ifndef GRANDPARENT_H
#define GRANDPARENT_H
... contents of Grandparent.h
#endif /* !GRANDPARENT_H */
```

<https://en.wikipedia.org/wiki/Pragma_once>
