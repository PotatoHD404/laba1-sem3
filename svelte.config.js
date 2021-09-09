import preprocess from "svelte-preprocess";
import vercel from '@sveltejs/adapter-vercel';

const config = {
  kit: {
    adapter: vercel(),
    target: '#svelte',
  },
  preprocess: [preprocess({
    "postcss": true
  })]
};

export default config;
