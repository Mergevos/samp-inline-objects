# samp-inline-objects

[![Mergevos](https://img.shields.io/badge/Mergevos-samp--inline--objects-2f2f2f.svg?style=for-the-badge)](https://github.com/Mergevos/samp-inline-objects)

Inline object editing.

## Installation

Simply install to your project:

```bash
sampctl package install Mergevos/samp-inline-objects
```

Include in your code and begin using the library:

```pawn
#include <inline-objects>
```

## Usage

There's only one function to use, pretty simple. 

```c
EditObjectInline(playerid, objectid, Func: func<iiiiiiiiii>);
```

Where's: 

```
playerid - Player who is editing an object.
objectid - The object which is edited.
func - Callback/Inline called after.

Returns value of EditObject. 1 for succes, 0 for fail.
```

## Example
```c

YCMD:test(playerid, params[], help)
{ 
    if(help) {
        return 0;
    }
    SelectObject(playerid);

    return 1;
}

public OnPlayerSelectObject(playerid, type, objectid, modelid, Float:fX, Float:fY, Float:fZ)
{
    inline Test(pid, playerobject, objid, response, Float:fXx, Float:fYy, Float:fZz, Float:fRotX, Float:fRotY, Float:fRotZ )
    {
        #pragma unused fRotZ, fRotY, fRotX, fZz, fYy, fXx, objid, playerobject, pid
        if(response == EDIT_RESPONSE_FINAL) {
            print("NOINDOINDIOW");
        }
        else if(response == EDIT_RESPONSE_CANCEL)  {
            print("PINOINDIO");
        }
        print("Test");
    }
    EditObjectInline(playerid, objectid, using inline Test);
    return 1;
}
```

## Testing

To test, simply run the package and then connect to the server:

```bash
sampctl package run
```
