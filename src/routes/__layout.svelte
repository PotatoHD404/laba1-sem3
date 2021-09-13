<script>
  import { theme } from '../stores/themeStore';
  import { onMount } from 'svelte';

  onMount(() => {
    document.addEventListener('load', () => {
      theme.set(localStorage.getItem('theme'));
      document.body.classList.add(value);
    }, { once: true });
  });

  // import { theme } from '../stores/themeStore';
  // import { theme } from '../stores/themeStore';
  // import { onMount } from 'svelte';

  // onMount(() => {
  //   window.document.body.classList.add('transition-none');
  //   theme.subscribe((theme, prevTheme) => {
  //     window.document.body.classList.remove(prevTheme);
  //     window.document.body.classList.add(theme);
  //   });
  //   // theme.set(theme);
  //   // console.log(theme);
  // });

  import '../app.postcss';

  const site_name = 'PotatoHD website';
  const description = 'Lab 1 sem 3 that can sort your data';
</script>
<svelte:head>
  <link rel='icon' href='/favicon.png'>
  <meta name='viewport' content='width=device-width, initial-scale=1'>
  <meta name='robots' content='follow, index'>
  <title>{site_name}</title>
  <meta content='{description}' name='description'>
  <meta property='og:title' content='{site_name}'>
  <!--  <meta property="og:image" content="/twitter.png">-->
  <!--  <meta name="twitter:card" content="summary_large_image">-->
  <meta name='twitter:title' content='{site_name}'>
  <meta name='twitter:description' content='{description}'>
  <!--  <meta name="twitter:image" content="/twitter.png">-->
</svelte:head>
<slot></slot>

<style>
    @tailwind base;
    @tailwind components;
    @tailwind utilities;
</style>