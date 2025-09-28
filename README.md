# MintVanilla
Mod for LeviLamina to enhance vanilla experience

### Commands
- `/tps` - Shows server tps
- `/restart <reconnect>` - Restarts server, if reconnect set to True server sends TransferPacket

### Tweaks
- [x] AllowClientResourcePack
- [x] FakeSeed
- [x] ForceTrustedSkin (Partially works)
- [x] HideOperator
- [x] BetterRestart

### Default config
If you want players to reconnect to your server after restart fill `serverIp` & `serverPort` with your public server ip.<br>
Or send players to hub or fallback server.
```json
{
    "version": 1,
    "tweaks": {
        "allowClientResourcePack": true,
        "fakeSeed": true,
        "forceTrustedSkin": true,
        "hideOperator": true
    },
    "commands": {
        "restartCommand": true,
        "tpsCommand": true
    },
    "extras": {
        "seed": -777,
        "tpsCommandAny": false,
        "tpsCommandFormat": "[TPS]: %tps%",
        "serverIp": "127.0.0.1",
        "serverPort": 19132
    }
}
```