#pragma once

// socket_container 连接服务端类
template <typename _socket, typename _real_select, typename _socket_store>
class socket_container
{
public:
	socket_container()
	{
	}
	~socket_container()
	{
	}
	enum _const
	{
		max_accept_per_frame = 50,
	};
public:
	FORCEINLINE bool ini(const net_server_param & param)
	{
		return m_socket.ini(param);
	}
	FORCEINLINE void tick()
	{
		// 处理新连接
		accept();

		// select现有连接
		select();

		// read现有连接
		tick_read();

		// write现有连接
		tick_write();

		// process现有连接的msg
		tick_process();
	}
private:
	FORCEINLINE bool accept()
	{
		if (m_socket.can_read())
		{
			_socket s;
			int32_t num = 0;
			while(m_socket.accept(s) && num < max_accept_per_frame)
			{
				// add to container
				m_socket_store.push_back(s);
				num++;
			}
		}
		return true;
	}
	FORCEINLINE bool select()
	{
		m_real_select.clear();

		// add
		for (_socket_store::iterator it = m_socket_store.begin(); it != m_socket_store.end(); it++)
		{
			_socket & s = *it;
			m_real_select.add(s.get_socket_t());
		}

		return m_real_select.select();
	}
	FORCEINLINE bool tick_read()
	{
		for (_socket_store::iterator it = m_socket_store.begin(); it != m_socket_store.end(); it++)
		{
			_socket & s = *it;
			if (m_real_select.is_read(s.get_socket_t()))
			{
				s.fill();
			}
		}

		return true;
	}
	FORCEINLINE bool tick_write()
	{
		for (_socket_store::iterator it = m_socket_store.begin(); it != m_socket_store.end(); it++)
		{
			_socket & s = *it;
			if (m_real_select.is_write(s.get_socket_t()))
			{
				s.flush();
			}
		}

		return true;
	}
	FORCEINLINE bool tick_process()
	{
		for (_socket_store::iterator it = m_socket_store.begin(); it != m_socket_store.end(); it++)
		{
			_socket & s = *it;
			
			// todo
		}

		return true;
	}
private:
	_socket m_socket;
	_real_select m_real_select;
	_socket_store m_socket_store;
};



