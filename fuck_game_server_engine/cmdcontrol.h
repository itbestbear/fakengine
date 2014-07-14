#pragma once

struct cmdcontrol
{
	bool is_set()
	{
		return isset == 1;
	}
	void clear()
	{
		memset(cmd, 0, sizeof(cmd));
		memset(param, 0, sizeof(param));
		isset = 0;
	}
	bool is_cmd(const int8_t * _cmd)
	{
		if (tstricmp((const char *)cmd, (const char *)_cmd) == 0)
		{
			return true;
		}
		return false;
	}
	bool set_cmd(const int8_t * _cmd, const int8_t * _param)
	{
		fstrcopy(cmd, _cmd, sizeof(cmd));
		fstrcopy(param, _param, sizeof(param));
		isset = 1;
		return true;
	}
	const int8_t * get_cmd()
	{
		return cmd;
	}
private:
	int8_t isset;
	int8_t cmd[c_CmdControlCmdSize];
	int8_t param[c_CmdControlCmdSize];
};
