#ifndef	__IDLLLOADER_H__
#define __IDLLLOADER_H__

#include	<string>
#include	<vector>

class IDllLoader
{
public:
  virtual	void	*open(const char *, int) = 0;
  virtual	char	*error(void) = 0;
  virtual	void	*sym(void *, const char *) = 0;
  virtual	int	close(void *) = 0;
  virtual	int	getNbrLibrary(void) = 0;
  virtual std::vector<std::string> getNameLibrary(void) = 0;
  virtual	bool	print_error(const std::string &) = 0;
private:

};

#endif
