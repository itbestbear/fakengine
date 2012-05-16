#pragma once

class fperf_node
{
public:
	force_inline fperf_node(const char * name, fperf_node * parent) : m_name(name),
		m_totalcalls(0),
		m_totaltime(0),
		m_starttime(0),
		m_recursioncounter(0),
		m_parent(parent),
		m_child(0),
		m_sibling(0)
	{
		reset();
	}
	force_inline fperf_node( const char* name ) : m_name(name),
		m_totalcalls(0),
		m_totaltime(0),
		m_starttime(0),
		m_recursioncounter(0),
		m_parent(0),
		m_child(0),
		m_sibling(0)
	{
		reset();
	}
	force_inline ~fperf_node()
	{
		SAFE_DELETE(fperf_node, m_child);
		SAFE_DELETE(fperf_node, m_sibling);
	}
	force_inline void call()
	{

	}
	force_inline bool ret()
	{
		return true;
	}
	force_inline void reset()
	{
		m_totalcalls = 0;
		m_totaltime = 0;
		if (m_child)
		{
			m_child->reset();
		}
		if (m_sibling)
		{
			m_sibling->reset();
		}
	}

	force_inline fperf_node * get_parent()
	{
		return m_parent;
	}
	force_inline fperf_node * get_sibling()
	{
		return m_sibling;
	}
	force_inline fperf_node * get_child()
	{
		return m_child;
	}
	force_inline const char * get_name()
	{
		return m_name;
	}
	force_inline uint32_t get_index()
	{
		return m_index;
	}
	force_inline uint32_t get_totalcalls()
	{
		return m_totalcalls;
	}
	force_inline uint64_t get_totaltime()
	{
		return m_totaltime;
	}

protected:
	const char * m_name;
	uint32_t m_totalcalls;
	uint64_t m_totaltime;
	uint64_t m_starttime;
	uint32_t m_recursioncounter;

	fperf_node * m_parent;
	fperf_node * m_child;
	fperf_node * m_sibling;

	uint32_t m_index;

	friend class fperf_manager;
};

class fperf_manager
{
public:
	force_inline fperf_manager() : m_root(0), m_current_node(0), m_total_node(0)
	{
	}
	force_inline ~fperf_manager()
	{

	}
	force_inline void sart_profile(const char * name)
	{
		if (name != m_current_node->get_name())
		{
			m_current_node = find_sub_node(m_current_node, name);
		} 
		m_current_node->call();
	}
	force_inline void stop_profile()
	{
		if (m_current_node->ret())
		{
			m_current_node = m_current_node->get_parent();
		}
	}
	force_inline fperf_node * find_sub_node(fperf_node * parent, const char * name)
	{
		fperf_node * child = parent->get_child();
		while (child)
		{
			if (child->get_name() == name)
			{
				return child;
			}
			child = child->get_sibling();
		}
		return create_new_node(name, parent);
	}
	fperf_node * create_new_node(const char * name, fperf_node * parent)
	{
		fperf_node * node = fnew<fperf_node, const char *, fperf_node *>(name, parent);
		node->m_index = m_total_node++;
		node->m_sibling = parent->get_child();
		parent->m_child = node;
		return node;
	}
private:
	fperf_node * m_root;
	fperf_node * m_current_node;
	uint32_t m_total_node;
};

// ����
class fperf_sample
{
public:
	force_inline fperf_sample(fperf_manager * manager, const char * name) :
	m_manager(manager)
	{ 
		m_manager->sart_profile(name); 
	}

	force_inline ~fperf_sample()					
	{ 
		m_manager->stop_profile(); 
	}
private:
	fperf_manager * m_manager;
};

extern THREAD_LOCAL_VALUE fperf_manager * g_fperf_manager;

#ifdef USE_PROFILE
#define	PERF(manager, name) fperf_sample _fperf_sample((manager), (name))
#else
#define	PERF(manager, name)
#endif

#define PERF_FUNC(manager) PERF(manager, __FUNCTION__)
#define PERF_DEFAULT(name) PERF(g_fperf_manager, name)
#define PERF_DEFAULT_FUNC() PERF(g_fperf_manager, __FUNCTION__)

