#ifndef STACK_TPP
# define STACK_TPP

using namespace ft;

template <class T, class Container> 
stack<T, Container>::stack (const container_type& ctnr)
{
	// cout << " stack constructor called " << endl;
	this->c = ctnr;
}

template <class T, class Container> 
stack<T, Container>::~stack (void)
{
	// cout << " stack destructor called " << endl;
}

template <class T, class Container> 
typename Container::reference stack<T, Container>::top(void)
{
	return(this->c.back());
}

template <class T, class Container> 
typename Container::const_reference stack<T, Container>::top(void) const
{
	return(this->c.back());
}

template <class T, class Container> 
bool stack<T, Container>::empty(void) const
{
	return(this->c.empty());
}

template <class T, class Container> 
typename Container::size_type	stack<T, Container>::size(void) const
{
	return(this->c.size());
}

template <class T, class Container> 
void	stack<T, Container>::push(const value_type& value)
{
	return(this->c.push_back(value));
}

template <class T, class Container> 
void	stack<T, Container>::pop()
{
	return(this->c.pop_back());
}

template <class T, class Container> 
typename stack<T, Container>::container_type	stack<T, Container>::get_stack() const
{
	return (this->c);
}

template <class T, class Container>
bool operator==(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
	return (lhs.get_stack() == rhs.get_stack());
}

template <class T, class Container> 
bool operator!=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
	return(lhs.get_stack() != rhs.get_stack());
}

template <class T, class Container> 
bool operator>=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
    return (lhs.get_stack() >= rhs.get_stack());
}

template <class T, class Container> 
bool operator<=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
    return (lhs.get_stack() <= rhs.get_stack());
}

template <class T, class Container> 
bool operator>(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
    return (lhs.get_stack() > rhs.get_stack());
}

template <class T, class Container> 
bool operator<(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
    return (lhs.get_stack() < rhs.get_stack());
}

template <class T, class Container> 
stack<T, Container>		&stack<T, Container>::operator=( const ft::stack<T, Container>& other )
{
	this->c = other._stack;
}



// template <class T, class Alloc>
// bool operator!=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
// {
//     return(!(lhs == rhs));
// }

// template <class T, class Alloc>
// bool operator<(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
// {
//     return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
// }
// template <class T, class Alloc>
// bool operator<=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
// {
//     return (!(rhs < lhs) || (rhs == lhs));
// }

// template <class T, class Alloc>
// bool operator>(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
// {
//     return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
// }
	
// template <class T, class Alloc>
// bool operator>=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
// {
//     return (!(rhs > lhs) || (rhs == lhs));
// }


#endif